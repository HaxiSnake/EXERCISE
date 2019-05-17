import Bank.*;
import org.omg.CosNaming.*;
import org.omg.CosNaming.NamingContextPackage.*;
import org.omg.CORBA.*;
import org.omg.PortableServer.*;
import org.omg.PortableServer.POA;
import java.util.Properties;

//分布式对象实现类
class AccountImpl extends AccountPOA
{
    private ORB orb;
    private int balanceVar;
    public void setORB(ORB orb_val){
        orb = orb_val; //保存ORB对象引用
    }
    public AccountImpl(){
        balanceVar=0;
    }
    public int Deposit(int amount){
        balanceVar+=amount;
        return balanceVar;
    }
    public int Withdraw(int amount){
        balanceVar-=amount;
        return balanceVar;
    }
    public int balance(){
        return balanceVar;
    }
}
public class BankCorbaServer{
    public static void main(String args[]){
        try {
            //ORB初始化
            ORB orb = ORB.init(args,null);
            //获取RootPOA的引用，并使POAManager变为活动状态
            POA rootpoa =
                POAHelper.narrow(orb.resolve_initial_references("RootPOA"));
            rootpoa.the_POAManager().activate();
            //生成Servant,并将ORB对象保存起来
            AccountImpl accountImpl = new AccountImpl();
            accountImpl.setORB(orb);
            //有Servant来获取Account对象的引用
            org.omg.CORBA.Object ref = rootpoa.servant_to_reference(accountImpl);
            Account href = AccountHelper.narrow(ref);
            //获取命名服务对象的引用
            org.omg.CORBA.Object objRef =
                                    orb.resolve_initial_references("NameService");
            NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);
            //将Account对象的引用登录到命名服务中
            String name="Account";
            NameComponent path[] = ncRef.to_name( name );
            ncRef.rebind(path,href);
            System.out.println("BankCorbaServer已经启动了！");
            //等待来自客户端的调用请求
            orb.run();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

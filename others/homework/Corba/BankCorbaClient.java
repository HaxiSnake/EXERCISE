import Bank.*;
import org.omg.CosNaming.*;
import org.omg.CosNaming.NamingContextPackage.*;
import org.omg.CORBA.*;

public class BankCorbaClient{
    static Account AccountImpl;
    public static void main(String args[]) {
        try {
            //ORB的初始化
            ORB orb = ORB.init(args,null);
            //获取命名服务对象的引用
            org.omg.CORBA.Object objRef = 
                                        orb.resolve_initial_references("NameService");
            NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);
            //从命名服务中获取Account对象的引用
            String name = "Account";
            AccountImpl = AccountHelper.narrow(ncRef.resolve_str(name));
            //调用Deposit()方法
            AccountImpl.Deposit(100);
            //调用实现只读属性的方法balance
            System.out.println("Balance="+AccountImpl.balance());
            //调用Withdraw()方法
            int bm = AccountImpl.Withdraw(30);
            System.out.println("Balance="+bm);
            bm = AccountImpl.Withdraw(20);
            bm = AccountImpl.balance();
            System.out.println("Balance="+bm);
        } catch (Exception e) {
            e.printStackTrace();
        }
        
    }
}
import java.rmi.*;
import java.rmi.registry.*;
import java.rmi.server.*;
import java.util.*;

public class DataTransServerImpl extends UnicastRemoteObject 
                                            implements DataTransServer
{
    ClientHash tbl = new ClientHash();
    public DataTransServerImpl() throws RemoteException{
        super();
    }

    public String login(DataTransClient c) throws DataTransServerBusyException,
                                                    RemoteException
    {
        String clientname = null;
        try{
            //保存调用该login()方法的客户端对象
            tbl.addClient(c,this.getClientHost());
        }catch(ServerNotActiveException e){
            tbl.addClient(c,"<unknown>");
        }
        try{
            clientname = tbl.getClientName(c);
        }catch(DataTransClientNotFoundException e){
            System.out.println("DataTransServerImpl err:"+e.getMessage());
            e.printStackTrace();
        }
        return clientname;
    }

    public void logout(DataTransClient c)
                    throws DataTransClientNotFoundException,RemoteException
    {
        tbl.delClient(c);
    }

    public void sendMessage(DataTransClient c,String s)
                    throws DataTransClientNotFoundException,RemoteException
    {
        String cname = tbl.getClientName(c);
        //将信息发送给所有已登录客户端
        tbl.broadcastMessage(cname + ":" + s);
    }

    public static void main(String args[]){
        System.setSecurityManager(new RMISecurityManager());
        try{
            //生成客户端使用的分布式对象
            DataTransServerImpl obj = new DataTransServerImpl();

            //为了使客户端能够获得分布式对象的引用
            //需要将所生成的分布式对象引用登录到RMIRegistry注册器中
            Naming.rebind("DataTransServer", obj);

            System.out.println("DataTransServer bound in registry");
        }
        catch(Exception e){
            System.out.println("DataTransServerImpl err:"+ e.getMessage());
            e.printStackTrace();
        }
    }
}

class ClientHash{
    final static int CLIENT_MAX = 6;
    int client_num=0;
    int client_count = 0;
    class Client{
        String name;
        DataTransClient robj;
        public Client(DataTransClient r,String s){
            robj = r;
            name = s;
        }
    }
    Hashtable c_hash = new Hashtable();

    public synchronized int addClient(DataTransClient r, String s)
                                throws DataTransServerBusyException
    {
        int no = client_num;
        if( no >= CLIENT_MAX){
            throw new DataTransServerBusyException("DataTransServerImpl:DataTransServer is busy!");
        }
        String cname = new String(s+"."+String.valueOf(client_count++));
        c_hash.put(r,cname);
        client_num++;
        //向各注册客户端发送注册信息
        broadcastMessage("<" + cname + " login>");
        return no;
    }

    public synchronized void delClient(DataTransClient r)
                                throws DataTransClientNotFoundException
    {
        String cname = getClientName(r);
        if( cname == null)
        {
            throw new DataTransClientNotFoundException("DataTransServerImpl:No this client!");
        }
        client_num--;
        c_hash.remove(r);
        //向各注册客户端发送注销消息
        broadcastMessage("<"+cname+" logout>");
    }

    public synchronized String getClientName(DataTransClient r)
                                throws DataTransClientNotFoundException
    {
        String cname = (String) c_hash.get(r);
        if( cname == null)
        {
            throw new DataTransClientNotFoundException("DataTransServerImpl:No this client!");
        }
        return cname;
    }
    public synchronized void broadcastMessage(String s){
        for(Enumeration item = c_hash.keys(); item.hasMoreElements();){
            try{
                DataTransClient c = (DataTransClient)(item.nextElement());
                //利用回调技术向客户端发送消息
                c.sendMessage(s);
            }
            catch(Exception e){
                 System.out.println("ClientHash exception:"+e.getMessage());
            }
        }
    }
}
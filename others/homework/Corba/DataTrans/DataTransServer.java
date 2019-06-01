public interface DataTransServer extends java.rmi.Remote 
{
    String login(DataTransClient c)
        throws DataTransServerBusyException,java.rmi.RemoteException;
    void logout(DataTransClient c)
        throws DataTransClientNotFoundException,java.rmi.RemoteException;
    void sendMessage(DataTransClient c, String s)
        throws DataTransClientNotFoundException,java.rmi.RemoteException;
}
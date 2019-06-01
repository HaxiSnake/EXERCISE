public interface DataTransClient extends java.rmi.Remote
{
	void sendMessage(String s)throws java.rmi.RemoteException;
}
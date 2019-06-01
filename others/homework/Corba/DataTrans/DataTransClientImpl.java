import java.awt.*;
import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;

public class DataTransClientImpl extends UnicastRemoteObject implements DataTransClient
{
	TextArea textarea;
	public DataTransClientImpl(TextArea t) throws RemoteException
	{
		super();
		textarea = t;
	}
	public void sendMessage(String s) throws RemoteException
	{
        textarea.append(s+"\n");
    }
}
import java.awt.*;
import java.awt.event.*;
import java.rmi.*;
import java.rmi.server.*;
import java.util.*;

public class DataTransApplet extends java.applet.Applet implements ActionListener
{
	Label title;
	TextArea display;
	TextField input;
	DataTransClientImpl client;
	DataTransServer server;
	String clientname;
	boolean init = false;
	
	public void init()
	{
	title = new Label("",Label.CENTER);
	display = new TextArea(20,40);
	display.setEditable(false);
	input = new TextField(40);
	input.addActionListener(this);
	setLayout(new GridLayout(3,0));
	add(title);
	add(display);
	add(input);
	try
	{
	//获得服务器的远程对象引用
	server = (DataTransServer)Naming.lookup("rmi://"+
					getCodeBase().getHost()+"/DataTransServer");
	//生成服务器使用的客户端远程对象
	client = new DataTransClientImpl(display);
	//将客户端远程对象登录到服务器中
	clientname = server.login(client);
	title.setText(clientname);
	init = true;
	}
	catch(Exception e)
	{
		System.out.println("DataTransApplet.init exception:"+e.getMessage());
		title.setText("Server busy!!");
		remove(input);
		remove(display);
	}
}
	public void destroy()
{
	try
	{
		if(init)
		{
			server.logout(client);
		}
	}
	catch(Exception e)
	{
		System.out.println("DataTransApplet exception:"+e.getMessage());
	}
	removeAll();
}

	public void actionPerformed(ActionEvent ev)
{
    if(ev.getSource() == input)
    {
        if(ev.getID()==ActionEvent.ACTION_PERFORMED){
            try
            {
            //将输入信息发送给服务器
                server.sendMessage(client,input.getText());
            }
            catch(Exception e)
            {
                System.out.println("DataTransApplet.actionPerformed exception:"+e.getMessage());                                                              
            }
            input.setText("");
        }
    }
}
}
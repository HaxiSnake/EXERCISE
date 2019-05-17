package Bank;


/**
* Bank/AccountPOA.java .
* 由IDL-to-Java 编译器 (可移植), 版本 "3.2"生成
* 从Bank.idl
* 2019年5月16日 星期四 下午09时37分42秒 CST
*/

public abstract class AccountPOA extends org.omg.PortableServer.Servant
 implements Bank.AccountOperations, org.omg.CORBA.portable.InvokeHandler
{

  // Constructors

  private static java.util.Hashtable _methods = new java.util.Hashtable ();
  static
  {
    _methods.put ("_get_balance", new java.lang.Integer (0));
    _methods.put ("Deposit", new java.lang.Integer (1));
    _methods.put ("Withdraw", new java.lang.Integer (2));
  }

  public org.omg.CORBA.portable.OutputStream _invoke (String $method,
                                org.omg.CORBA.portable.InputStream in,
                                org.omg.CORBA.portable.ResponseHandler $rh)
  {
    org.omg.CORBA.portable.OutputStream out = null;
    java.lang.Integer __method = (java.lang.Integer)_methods.get ($method);
    if (__method == null)
      throw new org.omg.CORBA.BAD_OPERATION (0, org.omg.CORBA.CompletionStatus.COMPLETED_MAYBE);

    switch (__method.intValue ())
    {
       case 0:  // Bank/Account/_get_balance
       {
         int $result = (int)0;
         $result = this.balance ();
         out = $rh.createReply();
         out.write_ulong ($result);
         break;
       }

       case 1:  // Bank/Account/Deposit
       {
         int amount = in.read_ulong ();
         int $result = (int)0;
         $result = this.Deposit (amount);
         out = $rh.createReply();
         out.write_ulong ($result);
         break;
       }

       case 2:  // Bank/Account/Withdraw
       {
         int amount = in.read_ulong ();
         int $result = (int)0;
         $result = this.Withdraw (amount);
         out = $rh.createReply();
         out.write_ulong ($result);
         break;
       }

       default:
         throw new org.omg.CORBA.BAD_OPERATION (0, org.omg.CORBA.CompletionStatus.COMPLETED_MAYBE);
    }

    return out;
  } // _invoke

  // Type-specific CORBA::Object operations
  private static String[] __ids = {
    "IDL:Bank/Account:1.0"};

  public String[] _all_interfaces (org.omg.PortableServer.POA poa, byte[] objectId)
  {
    return (String[])__ids.clone ();
  }

  public Account _this() 
  {
    return AccountHelper.narrow(
    super._this_object());
  }

  public Account _this(org.omg.CORBA.ORB orb) 
  {
    return AccountHelper.narrow(
    super._this_object(orb));
  }


} // class AccountPOA

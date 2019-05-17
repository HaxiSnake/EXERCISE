package Bank;


/**
* Bank/AccountHelper.java .
* 由IDL-to-Java 编译器 (可移植), 版本 "3.2"生成
* 从Bank.idl
* 2019年5月16日 星期四 下午09时37分42秒 CST
*/

abstract public class AccountHelper
{
  private static String  _id = "IDL:Bank/Account:1.0";

  public static void insert (org.omg.CORBA.Any a, Bank.Account that)
  {
    org.omg.CORBA.portable.OutputStream out = a.create_output_stream ();
    a.type (type ());
    write (out, that);
    a.read_value (out.create_input_stream (), type ());
  }

  public static Bank.Account extract (org.omg.CORBA.Any a)
  {
    return read (a.create_input_stream ());
  }

  private static org.omg.CORBA.TypeCode __typeCode = null;
  synchronized public static org.omg.CORBA.TypeCode type ()
  {
    if (__typeCode == null)
    {
      __typeCode = org.omg.CORBA.ORB.init ().create_interface_tc (Bank.AccountHelper.id (), "Account");
    }
    return __typeCode;
  }

  public static String id ()
  {
    return _id;
  }

  public static Bank.Account read (org.omg.CORBA.portable.InputStream istream)
  {
    return narrow (istream.read_Object (_AccountStub.class));
  }

  public static void write (org.omg.CORBA.portable.OutputStream ostream, Bank.Account value)
  {
    ostream.write_Object ((org.omg.CORBA.Object) value);
  }

  public static Bank.Account narrow (org.omg.CORBA.Object obj)
  {
    if (obj == null)
      return null;
    else if (obj instanceof Bank.Account)
      return (Bank.Account)obj;
    else if (!obj._is_a (id ()))
      throw new org.omg.CORBA.BAD_PARAM ();
    else
    {
      org.omg.CORBA.portable.Delegate delegate = ((org.omg.CORBA.portable.ObjectImpl)obj)._get_delegate ();
      Bank._AccountStub stub = new Bank._AccountStub ();
      stub._set_delegate(delegate);
      return stub;
    }
  }

  public static Bank.Account unchecked_narrow (org.omg.CORBA.Object obj)
  {
    if (obj == null)
      return null;
    else if (obj instanceof Bank.Account)
      return (Bank.Account)obj;
    else
    {
      org.omg.CORBA.portable.Delegate delegate = ((org.omg.CORBA.portable.ObjectImpl)obj)._get_delegate ();
      Bank._AccountStub stub = new Bank._AccountStub ();
      stub._set_delegate(delegate);
      return stub;
    }
  }

}

package Bank;

/**
* Bank/AccountHolder.java .
* 由IDL-to-Java 编译器 (可移植), 版本 "3.2"生成
* 从Bank.idl
* 2019年5月16日 星期四 下午09时37分42秒 CST
*/

public final class AccountHolder implements org.omg.CORBA.portable.Streamable
{
  public Bank.Account value = null;

  public AccountHolder ()
  {
  }

  public AccountHolder (Bank.Account initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = Bank.AccountHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    Bank.AccountHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return Bank.AccountHelper.type ();
  }

}

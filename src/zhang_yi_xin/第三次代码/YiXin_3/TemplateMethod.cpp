/*
 * 作者:张艺馨
 * 编写日期:2018/9/13
 * 功能描述:在数据库操作模板类中定义四个方法分别对应数据库一般操作连接,打开,使用,关闭.对于不同的数据库,操作步骤一致,只是连接数据库方法有所区别.
 *         使用模板方法模式对其进行设计
 */

#include <iostream>
using namespace std;
/*
 * 类名:DBOperator
 * 编写日期:18-9-13
 * 功能描述:抽象数据库操作类,充当模式中的抽象父类的角色
 */
class DBOperator
{
public:
    virtual void conn_db() = 0;  /*连接数据库*/
    void open_db(){
        cout<<"打开数据库"<<endl;
    }
    void use_db(){
        cout<<"使用数据库"<<endl;
    }
    void close_db(){
        cout<<"关闭数据库"<<endl;
    }
    void process(){
        conn_db();
        open_db();
        use_db();
        close_db();
    }
};

/*
 * 类名:SQLServerDBOperator
 * 编写日期:18-9-13
 * 功能描述:具体数据库操作类,充当模式中的具体子类的角色
 */
class SQLServerDBOperator : public DBOperator
{
public:
    void conn_db(){
        cout<<"连接SQL Server数据库"<<endl;
    }
};

/*
 * 类名:OracleDBOperator
 * 编写日期:18-9-13
 * 功能描述:具体数据库操作类,充当模式中的具体子类的角色
 */
class OracleDBOperator : public DBOperator
{
public:
    void conn_db(){
        cout<<"连接Oracle数据库"<<endl;
    }
};

int main() {
    DBOperator *db_operator;

    db_operator=new SQLServerDBOperator();
    db_operator->process();
    
    cout<<"-----------------------------------"<<endl;

    db_operator=new OracleDBOperator();
    db_operator->process();

    return 0;
}
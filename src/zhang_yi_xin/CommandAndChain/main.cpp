/*
 * 作者:张艺馨
 * 编写日期:2018/9/8
 * 功能描述:开发一个软件系统的在线文档帮助系统,用户可以在任何一个查询环境中输入查询关键字,如果当前环境无相关内容,系统
 *         将查询按一定顺序转发给其他查询环境,
 */
#include <iostream>
#include <string>
using namespace std;
/*
 * 类名:SearchContext
 * 编写日期:18-9-8
 * 功能描述:充当抽象处理者
 */
class SearchContext
{
protected:
    SearchContext *search_context_;
public:
    void set_successor(SearchContext *search_context_){
        this->search_context_=search_context_;
    }
    virtual void search(string keyword)=0 ;
};

/*
 * 类名:JavaSearchContext
 * 编写日期:18-9-8
 * 功能描述:具体处理者,具体处理请求处理上下文
 */
class JavaSearchContext : public SearchContext
{
    string::size_type idx;
public:
    void search(string keyword) {
        idx = keyword.find("java");
        if (idx == string::npos) {  /*不存在*/
            search_context_->search(keyword);
        }
        else{
            cout<<"查询关键字java!"<<endl;
        }
    }
};

/*
 * 类名:SQLSearchContext
 * 编写日期:18-9-8
 * 功能描述:具体处理者,具体处理请求处理上下文
 */
class SQLSearchContext : public SearchContext
{
    string::size_type idx;
public:
    void search(string keyword) {
        idx = keyword.find("SQL");
        if (idx == string::npos) {  /*不存在*/
            search_context_->search(keyword);
        }
        else{
            cout<<"查询关键字SQL!"<<endl;
        }
    }
};

/*
 * 类名:UMLSearchContext
 * 编写日期:18-9-8
 * 功能描述:具体处理者,具体处理请求处理上下文
 */
class UMLSearchContext : public SearchContext
{
    string::size_type idx;
public:
    void search(string keyword) {
        idx = keyword.find("UML");
        if (idx == string::npos) {  /*不存在*/
            search_context_->search(keyword);
        }
        else{
            cout<<"查询关键字UML!"<<endl;
        }
    }
};

int main() {
    SearchContext *j_context,*s_context,*u_context;
    j_context=new JavaSearchContext();
    s_context=new SQLSearchContext();
    u_context=new UMLSearchContext();
    j_context->set_successor(s_context); /*j_context首先处理,不能处理转发请求给下家*/
    s_context->set_successor(u_context);  /*职责连是客户端创建,请求传递顺序也是客户端确定*/
    string keyword="UML类图";
    j_context->search(keyword); /*向j_context对象传递查询UML*/
    return 0;
}
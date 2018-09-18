int Prioritize(int );
//对x和y的初始化实际是完全一致,可以看到，
//x(或y)的初始化需要循环调用函数Prioritize,并且在Prioritize抛出异常的时候对x(或y)赋默认值0。
int AllWorks(int times){
    int i;
    int x;  //由于初始化要在运行时修改x的值，因此，虽然x在初始化之
            //    后对于程序而言是个常量，却不能被声明为const。
    try {
        for (i = 0; i < times; i++)
            x += Prioritize(i);
    }
    catch(...) {
        x = 0;
    }

    const int y = [=]{      //在定义y的时候，由于我们就地定义lambda函数并且调用，
                            // y仅需使用其返回值，于是常量性得到了保证。是lambda函数的一个优势所在
        int i, val;
        try {
            for (i = 0; i < times; i++)
                val += Prioritize(i);
        }
        catch(...) {
            val = 0;
        }
        return val;
    }();
}



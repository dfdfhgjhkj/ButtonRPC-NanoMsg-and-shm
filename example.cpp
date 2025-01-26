/*server:*/
#include <ButtonRPC.hpp>
int print(int a)
{
    std::cout << a << std::endl;
    return 1;
}
int main(void)
{
    ButtonRPC* rpc = new ButtonRPC();    
    rpc->as_server("shm",5050);
    rpc->regist("print111", &print);

    rpc->run();
    return 0;
}
/*client:*/
#include <ButtonRPC.hpp>

int main(void)
{
    ButtonRPC* rpc = new ButtonRPC();
    rpc->as_client("shm",5050);
    rpc->call<int>("print111", int(100)).value();
    return 0;
}

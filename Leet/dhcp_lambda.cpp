#include <iostream>
#include <vector>
using namespace std;

auto generate_dhcp_fn(int len, int low, int high)
{
    auto fun = [len, low, high]() -> string
    {
        static vector<int> v(len, low);

        static int w = 0;
        int i, flag = 0;
        string ip;
        static int stop = 0;

        if (stop == 1)
        {
            return "Exit";
        }

        for (auto el : v)
        {
            ip += to_string(el) + ".";
        }

        if (v[0] >= high)
        {
            for (i = 0; i <= w; i++)
            {
                if (v[i] < high)
                {
                    v[i] += 1;
                    flag = 1;
                    break;
                }
                else
                {
                    v[i] = 0;
                }
            }
            if (flag != 1)
            {
                w++;
                if (w >= len)
                {
                    stop  = 1;
                }
                else
                {
                    v[w] = 1;
                    v[0] = 0;
                }
            }
        }
        else
        {
            v[0] += 1;
        }
        

        return ip;
    };
    return fun;
}

int main()
{
    auto ip_genarator = generate_dhcp_fn(4, 0, 255);
    string result;
    for (int i = 0; i < 256*256*256; i++)
    {
        result = ip_genarator();
    }
    cout << result << endl;
    return 0;
}
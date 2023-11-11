#include <iostream>
#include <vector>
using namespace std;

class generate_dhcp_fn
{
    int len;
    int low;
    int high;
    int w = 0, stop = 0;
    vector<int> v;
    
    public:
    generate_dhcp_fn(int len_1, int low_1, int high_1): len(len_1), low(low_1), high(high_1) {
        for (int i=0;i<len;i++) {
            v.push_back(0);
        }
    }

    string ip_generator() {
        int i, flag = 0;
        string ip;

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
    }
};

int main()
{
    generate_dhcp_fn ip(4, 0, 255);
    generate_dhcp_fn hash(4, 0, 127);
    string result1, result2;
    for (int i = 0; i < 256*256*256; i++)
    {
        result1 = ip.ip_generator();
        result2 = hash.ip_generator();
    }
    cout << result1 << ": " << result2 << endl;
    
    return 0;
}
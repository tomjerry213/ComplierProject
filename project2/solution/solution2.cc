#include "Generator.h"

char lsy[55];
char leo[55];

int main() {

    for (int i = 1; i <= 10; i++) {
        sprintf(lsy, "./cases/case%d.json", i);
        std::cout << "Operating On" <<  lsy << std::endl;
        sprintf(leo, "./kernels/grad_case%d.cc", i);
        std::string ans =  generate(lsy);
        freopen(leo, "w", stdout);
        std::cout << ans << std::endl;
        freopen("/dev/tty", "w", stdout);
    }
}
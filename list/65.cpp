#include <iostream>
#include <vector>

int main()
{
    int L, M;
    std::cin >> L >> M;
    std::vector<int> magicCube(L, 1);

    for (int i = 0; i < M; ++i)
    {
        int operation, start, end;
        std::cin >> operation >> start >> end;

        if (operation == 1)
        {
            for (int j = start - 1; j < end; ++j)
            {
                magicCube[j] = (magicCube[j] % 4) + 1;
            }
        }
        else if (operation == 2)
        {
            // 操作2，使区间上魔方的东面点数-1
            for (int j = start - 1; j < end; ++j)
            {
                magicCube[j] = (magicCube[j] - 2 + 4) % 4 + 1;
            }
        }
        else if (operation == 3)
        {
            // 操作3，使区间上魔方1,3对换，2,4对换
            for (int j = start - 1; j < end; ++j)
            {
                std::swap(magicCube[j], magicCube[j + (end - start + 1) / 2]);
            }
        }
    }

    // 统计最后1到L上东面点数为4的魔方个数
    int count = 0;
    for (int i = 0; i < L; ++i)
    {
        if (magicCube[i] == 4)
        {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}

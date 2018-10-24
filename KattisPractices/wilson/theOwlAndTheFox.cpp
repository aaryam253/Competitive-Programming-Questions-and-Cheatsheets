#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
	int num_cases;
	scanf("%d", &num_cases);
	int num, sum;

	for (int i = 0; i < num_cases; ++i)
	{
		scanf("%d", &num);
		int num_t = num;
		sum = 0;

		while(num_t) {
			sum += num_t%10;
			num_t /= 10;
		}
		num_t = sum;

		for (int i = num; i >= 0; --i)
		{
			int absolute = i;
			sum = 0;
			while(absolute) {
				sum += absolute%10;
				absolute /= 10;
			}
			if (num_t-1 == sum) {
				printf("%d\n", i);
				break;
			}
		}
	}

	
	
	return 0;
}
#include <cstring>
#include <cstdio>

class KMP {
public:
	KMP() {
		W = new char[1001000];
		pi = new int[1001000];
	}
	~KMP() {
		delete[] W;
		delete[] pi;
	}
	void setW() {
		scanf("%s", W);
	}
	void fail() {
		int len = strlen(W);
		pi[0] = -1;
		cur_pos = -1;
		for(int i = 1;i < len;++i) {
			while(cur_pos >= 0 && W[i] != W[cur_pos + 1]) {
				cur_pos = pi[cur_pos];
			}
			if(W[i] == W[cur_pos + 1]) pi[i] = ++cur_pos;
			else pi[i] = cur_pos;

			if(pi[i] + 1 && !((i + 1) % (i - pi[i]))) {
				printf("%d %d\n", i + 1, (i + 1) / (i - pi[i]));
			}
		}
	}
private:
	int cur_pos;
	char* W;
	int* pi;
};

int main()
{
	int num, test_case = 0;
	while(scanf("%d", &num) != EOF) {
		if(num) {
			if(test_case) puts("");
			printf("Test case #%d\n", ++test_case);
			KMP* K = new KMP;
			K->setW();
			K->fail();
			delete K;
		}
		else break;
	}
	return 0;
}

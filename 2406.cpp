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
	int setW() {
		scanf("%s", W);
		if(strlen(W) == 1 && W[0] == '.') return 0;
		return 1;
	}
	int fail() {
		int len = strlen(W);
		int temp = 1;
		pi[0] = -1;
		cur_pos = -1;
		for(int i = 1;i < len;++i) {
			while(cur_pos >= 0 && W[i] != W[cur_pos + 1]) {
				cur_pos = pi[cur_pos];
			}
			if(W[i] == W[cur_pos + 1]) pi[i] = ++cur_pos;
			else pi[i] = cur_pos;
		}
		if(pi[len - 1] + 1 && !((len) % (len - 1 - pi[len - 1]))) {
			return (len) / (len - 1 - pi[len - 1]);
		}
		else return 1;
	}
private:
	int cur_pos;
	char* W;
	int* pi;
};

int main()
{
	KMP* K = new KMP;
	while(K->setW()) printf("%d\n", K->fail());
	return 0;
}

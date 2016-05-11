#include <cstring>
#include <cstdio>

class KMP {
public:
	KMP() {
		W = new char[10010];
		T = new char[1000100];
		pi = new int[10010];
	}
	~KMP() {
		delete[] W;
		delete[] T;
		delete[] pi;
	}
	void setW() {
		scanf("%s", W);
	}
	void setT() {
		scanf("%s", T);
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
		}
	}
	int match() {
		int cnt = 0;
		int lW = strlen(W);
		int lT = strlen(T);
		cur_pos = -1;
		for(int i = 0;i < lT;++i) {
			while(cur_pos >= 0 && T[i] != W[cur_pos + 1]) {
				cur_pos = pi[cur_pos];
			}
			if(T[i] == W[cur_pos + 1]) ++cur_pos;
			if(cur_pos + 1 == lW) {
				++cnt;
				cur_pos = pi[cur_pos];
			}
		}
		return cnt;
	}
private:
	int cur_pos;
	char* W;
	char* T;
	int* pi;
};

int main()
{
	int cases;
	scanf("%d", &cases);
	while(cases--) {
		KMP* K = new KMP;
		K->setW();
		K->setT();
		K->fail();
		printf("%d\n", K->match());
		delete K;
	}
}

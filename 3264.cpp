#include<cstdio>
#include<algorithm>
using namespace std;

struct Node {
	Node* left;
	Node* right;
	int l, r, max, min;
};

class SegTree {
public:
	SegTree(int n) {
		Nodecount = 0;
		MAXNUM = n;
		Tree = new Node[(n << 2) + 1];
		num = new int[n + 1];
		ans_max = 0;
		ans_min = 2147483647;
	};
	~SegTree() {
		delete [] Tree;
		delete [] num;
	};
	void setNum() {
		for(int i = 1;i <= MAXNUM;++i) {
			scanf("%d", num + i);
		}
	};
	void Build() {
		Tree -> l = 1;
		Tree -> r = MAXNUM;
		if(1 == MAXNUM) {
			Tree -> max = num[0];
			Tree -> min = num[0];
			return;
		}
		else {
			Tree -> left = Tree + (++Nodecount);
			Tree -> right = Tree + (++Nodecount);
			int m = (1 + MAXNUM) >> 1;
			Build(Tree -> left, 1, m);
			Build(Tree -> right, m + 1, MAXNUM);
			Tree -> max = max(Tree -> left -> max, Tree -> right -> max);
			Tree -> min = min(Tree -> left -> min, Tree -> right -> min);
		}
	};
	void Build(Node* N, int l, int r) {
		N -> l = l;
		N -> r = r;
		if(l == r) {
			N -> max = num[l];
			N -> min = num[l];
			return;
		}
		else {
			N -> left = Tree + (++Nodecount);
			N -> right = Tree + (++Nodecount);
			int m = (l + r) >> 1;
			Build(N -> left, l, m);
			Build(N -> right, m + 1, r);
			N -> max = max(N -> left -> max, N -> right -> max);
			N -> min = min(N -> left -> min, N -> right -> min);
		}
	};
	void Update(int pos, int change) {
		if(Tree -> l == Tree -> r) {
			Tree -> max += change;
			Tree -> min += change;
			return;
		}
		else {
			int m = (Tree -> l + Tree -> r) >> 1;
			if(pos <= m) Update(Tree -> left, pos, change);
			else Update(Tree -> right, pos, change);
			Tree -> max = max(Tree -> left -> max, Tree -> right -> max);
			Tree -> min = min(Tree -> left -> min, Tree -> right -> min);
		}
	};
	void Update(Node* N, int pos, int change) {
		if(N -> l == N -> r) {
			N -> max += change;
			N -> min += change; 
			return;
		}
		else {
			int m = (N -> l + N -> r) >> 1;
			if(pos <= m) Update(N -> left, pos, change);
			else Update(N -> right, pos, change);
			N -> max = max(N -> left -> max, N -> right -> max);
			N -> min = min(N -> left -> min, N -> right -> min);
		}
	};
	int Max(int l, int r) {
		if(Tree -> l == l && Tree -> r == r) {
			ans_max = max(Tree -> max, ans_max);
		}
		else {
			int m = (Tree -> l + Tree -> r) >> 1;
			if(r <= m) Max(Tree -> left, l, r);
			else if(l > m) Max(Tree -> right, l, r);
			else {
				Max(Tree -> left, l, m);
				Max(Tree -> right, m + 1, r);
			}
		}
		int temp = ans_max;
		ans_max = 0;
		return temp;
	};
	void Max(Node* N, int l, int r) {
		if(N -> l == l && N -> r == r) {
			ans_max = max(N -> max, ans_max);
		}
		else {
			int m = (N -> l + N -> r) >> 1;
			if(r <= m) Max(N -> left, l, r);
			else if(l > m) Max(N -> right, l, r);
			else {
				Max(N -> left, l, m);
				Max(N -> right, m + 1, r);
			}
		}
	};
	int Min(int l, int r) {
		if(Tree -> l == l && Tree -> r == r) {
			ans_min = min(Tree -> min, ans_min);
		}
		else {
			int m = (Tree -> l + Tree -> r) >> 1;
			if(r <= m) Min(Tree -> left, l, r);
			else if(l > m) Min(Tree -> right, l, r);
			else {
				Min(Tree -> left, l, m);
				Min(Tree -> right, m + 1, r);
			}
		}
		int temp = ans_min;
		ans_min = 2147483647;
		return temp;
	};
	void Min(Node* N, int l, int r) {
		if(N -> l == l && N -> r == r) {
			ans_min = min(N -> min, ans_min);
		}
		else {
			int m = (N -> l + N -> r) >> 1;
			if(r <= m) Min(N -> left, l, r);
			else if(l > m) Min(N -> right, l, r);
			else {
				Min(N -> left, l, m);
				Min(N -> right, m + 1, r);
			}
		}
	};
private:
	int Nodecount;
	int MAXNUM;
	int ans_max;
	int ans_min;
	int* num;
	Node* Tree;
};

int main()
{
	int m, n, a, b;
	while(scanf("%d%d", &m, &n) != EOF) {
		SegTree *ST = new SegTree(m);
		ST -> setNum();
		ST -> Build();
		while(n--) {
			scanf("%d%d", &a, &b);
			printf("%d\n", ST -> Max(a, b) - ST -> Min(a, b));
		}
		delete ST;
	}
	return 0;
}

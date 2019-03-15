#include<iostream>
#include<cstring>
using namespace std;

int trie[100001][101];
bool stop[100001];
char s[100];
int tot;

void insert(int root, char *s)
{
    int i;
    int id;
    int len = strlen(s);
    for(i = 0; i < len; i++)
    {
        id = s[i] - 'a';
        if(!trie[root][id])
        {
            trie[root][id] = ++tot;
        }
        root = trie[root][id];
    }
    stop[root] = 1;
}

bool find(int root, char *s)
{
    int i;
    int id;
    int len = strlen(s);
    for(i = 0; i < len; i++)
    {
        id = s[i] - 'a';
        if(!trie[root][id])
        {
            return 0;
        }
        else
        {
            root = trie[root][id];
        }
    }
    return stop[root];
}
int main(void)
{
    int n, m, i;

    while((cin >> n >> m) && n != 0 && m != 0)
    {
        memset(trie, 0, sizeof(trie));
        memset(stop, 0, sizeof(stop));
        tot = 0;
        for(i = 0; i < n; i++)
        {
            cin >> s;
            insert(0, s);
        }
        for(i = 0; i < m; i++)
        {
            cin >> s;
            if(find(0, s) == 1)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}

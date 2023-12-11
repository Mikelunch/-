#include<iostream>
using namespace std;

const int N = 1e7;
int e[N], ne[N]; //�ڵ�ֵ���ڵ�ָ�����һ���ڵ���±�
int head, idx; //head:ͷ�ڵ��±� idx:�ص���� �����ָ��δ������������ͷ�����൱�ڶ�̬���������е�new����
//idxһ��ֻ�������ָ�����δʹ�õ��Ľڵ� Ĭ�ϲ������ڴ�й©�ͻ���

void init() {//��̬�����ʼ��
    head = -1; //ͷ�ڵ�ָ���
    idx = 0;//��������ռ�e[N]δ��ʹ�ã�����ָ��e[0];
}

void insert_to_head(int x) { //��xֵ���뵽����ͷ��
    e[idx] = x; //�����ڴ�ռ��ֵΪx���½ڵ�
    ne[idx] = head;//�²���Ľڵ�ָ��ԭ�ȵ�ͷ�ڵ�
    head = idx; //ͷ�ڵ�ָ���²���Ľڵ�
    idx++;//ָ���µ��ڴ�ռ�
}

void insert_to_k(int k, int x) { //��x���뵽�±���k�Ľڵ�� 
    e[idx] = x;//����ռ�
    ne[idx] = ne[k]; //�����½ڵ��ָ��
    ne[k] = idx;//�����򱬸�ԭ���±�Ϊk�Ľڵ��ָ��
    idx++;
}


void remove_k_next(int k) { //ɾ���±�Ϊk�Ľڵ�ָ�����һ���ڵ㣨ע�ⲻҪ���
    ne[k] = ne[ne[k]];
}

void display() {
    for (int i = head; i != -1; i = ne[i]) {
        cout << e[i] << " ";
    }
    cout << endl;
}

int main() {
    int m;
    cin >> m;
    init(); //��ʼ����̬����
    while (m--) {
        int k, x; //�ڵ�λ�� �ڵ�ֵ
        char op; //��������

        cin >> op;

        if (op == 'H') {//ִ�в��뵽�ڵ�ͷ������
            cin >> x;
            insert_to_head(x);
            //display();
        }
        if (op == 'D') { //ִ��ɾ������
            cin >> k;
            if (!k) head = ne[head]; //ɾ��ͷ�ڵ�
            remove_k_next(k - 1); //ע�������k��ָ��k�β������� ��k�Ǵ�1��ʼ��
            //display();
        }
        if (op == 'I') {//ָ��������
            cin >> k >> x;
            insert_to_k(k - 1, x);//ע�������k��ָ��k�β������� ��k�Ǵ�1��ʼ��
            //display();
        }
    }
    display();
    return 0;
}
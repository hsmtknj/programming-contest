#include <bits/stdc++.h>

class Heap
{
public:
    Heap();
    ~Heap();

    void insert(int key);
    int get_max();
    void pop_root();
    std::vector<int> sort(std::vector<int> &vec);

    std::vector<int> v;
};

Heap::Heap()
{
}

Heap::~Heap()
{
}

void Heap::insert(int key)
{
    // 空であればそのまま挿入
    if (this->v.empty())
        this->v.push_back(key);
    // 空でなければ一旦最後尾に追加し，親との比較を続ける
    else
    {
        // 最後尾に挿入
        this->v.push_back(key);

        // 親との比較を続ける
        int target_ind = this->v.size() - 1;
        while (target_ind > 0)
        {
            int parent_ind = (target_ind - 1) / 2;
            if (this->v[parent_ind] < this->v[target_ind])
            {
                std::swap(this->v[parent_ind], this->v[target_ind]);
                target_ind = parent_ind;
            }
            else
                break;
        }
    }
}

int Heap::get_max()
{
    return this->v[0];
}

void Heap::pop_root()
{
    // 空であれば何もしない
    if (this->v.empty())
        return;
    // 空でない場合は削除を実行
    else
    {
        // ルートを削除して，最後尾の要素をルートに新たに設定
        std::swap(this->v[0], this->v[this->v.size() - 1]);
        this->v.pop_back();

        // ヒープ木の条件が満たされるまでスワップを繰り替えす
        //      子と比較して，大きい方の子とスワップ
        int target_ind = 0;
        bool flag = true;
        while (flag)
        {
            int left_ind = 2 * target_ind + 1;
            int right_ind = 2 * target_ind + 2;
            std::cout << target_ind << ", " << left_ind << ", " << right_ind << ", " << this->v.size() << std::endl;

            // 対象ノードが左右の子以上の値 or 子がいない状態であれば終了

            // 子がいないとき
            if (left_ind >= this->v.size())
                flag = false;
            // 子が1つ (左だけ) のとき
            else if (right_ind >= this->v.size())
            {
                // 左の子の方が大きい場合はスワップ
                if (this->v[target_ind] < this->v[left_ind])
                {
                    std::swap(this->v[target_ind], this->v[left_ind]);
                    target_ind = left_ind;
                }
                // そうでなければ終了
                else
                    flag = false;
            }
            // 子が2つのとき
            else
            {
                // 左右より大きいときは終了
                if (this->v[target_ind] >= this->v[left_ind] && this->v[target_ind] >= this->v[right_ind])
                    flag = false;
                else
                {
                    if (this->v[left_ind] > this->v[right_ind])
                    {
                        std::swap(this->v[target_ind], this->v[left_ind]);
                        target_ind = left_ind;
                    }
                    else
                    {
                        std::swap(this->v[target_ind], this->v[right_ind]);
                        target_ind = right_ind;
                    }
                }
            }
        }
    }
}

std::vector<int> Heap::sort(std::vector<int> &vec)
{
    std::vector<int> sorted_v;

    if (vec.empty())
        return sorted_v;
    else
    {
        // まず要素をヒープ木に挿入
        for (int i = 0; i < vec.size(); i++)
            this->insert(vec[i]);

        // ヒープ木から最大値を取り出し・ルートの削除を繰り返す
        int iter_num = vec.size();
        for (int i = 0; i < iter_num; i++)
        {
            // 最大を取り出す
            sorted_v.push_back(this->get_max());
            // ルートを削除する
            this->pop_root();
        }
    }
    return sorted_v;
}

int main()
{
    std::vector<int> v = {30, 88, 17, 12, 20, 25};

    // Heap h;
    // for (int i = 0; i < v.size(); i++)
    //     h.insert(v[i]);
    // for (int i = 0; i < h.v.size(); i++)
    //     std::cout << h.v[i] << " ";
    // std::cout << std::endl;
    // std::cout << h.get_max() << std::endl;

    // h.pop_root();
    // for (int i = 0; i < h.v.size(); i++)
    //     std::cout << h.v[i] << " ";
    // std::cout << std::endl;

    Heap h_sort;
    std::vector<int> sorted_v = h_sort.sort(v);
    for (int i = 0; i < sorted_v.size(); i++) std::cout << sorted_v[i] << " ";
    std::cout << std::endl;

    return 0;
}
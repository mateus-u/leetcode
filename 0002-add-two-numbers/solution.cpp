using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr && l2 == nullptr)
            return nullptr;

        int l1Val = l1 != nullptr ? l1->val : 0;
        int l2Val = l2 != nullptr ? l2->val : 0;

        int sum = l1Val + l2Val;

        if (sum > 9)
        {
            if (l1 != nullptr && l1->next != nullptr)
            {
                l1->next->val++;
            }
            else if (l2 != nullptr && l2->next != nullptr)
            {
                l2->next->val++;
            }
            else
            {
                return new ListNode(sum % 10, new ListNode(1));
            }
        }

        return new ListNode(sum % 10, addTwoNumbers(l1 != nullptr ? l1->next : nullptr, l2 != nullptr ? l2->next : nullptr));
    }
};

int main()
{
    auto solution = new Solution();

    ListNode *l1, *l2;

    ListNode *result = solution->addTwoNumbers(l1, l2);
}
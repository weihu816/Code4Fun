// Print subsets
// 0 <= k <= n, k numbers from 1, 2, ..., n
import java.util.ArrayList;
import java.util.List;

public class Solution {
    // 1st approach - recursion
    public static int count = 0;

    public static List<List<Integer>> getSubsets(int k, int n) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        if (k == 0 || k > n)
            return ans;
        if (k == 1) {
            for (int i = 1; i <= n; i++) {
                List<Integer> newList = new ArrayList<>();
                newList.add(i);
                ans.add(newList);
            }
            return ans;
        } else if (k == n) {
            List<Integer> newList = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                newList.add(i);
            }
            ans.add(newList);
            return ans;
        }
        List<List<Integer>> list1 = getSubsets(k, n - 1);
        List<List<Integer>> list2 = getSubsets(k - 1, n - 1);
        for (List<Integer> list : list2) {
            list.add(n);
        }
        ans.addAll(list1);
        ans.addAll(list2);
        return ans;
    }

    // 2st approach - recursion
    public static List<List<Integer>> getSubsets2(int k, int n) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> subset = new ArrayList<>();
        helper(ans, subset, k, n, 1);
        return ans;
    }

    public static void helper(List<List<Integer>> ans, List<Integer> subset, int k, int n, int num) {
        if (subset.size() == k) {
            ans.add(new ArrayList<>(subset));
            return;
        }
        for (int i = num; i <= n; i++) {
            subset.add(i);
            helper(ans, subset, k, n, i + 1);
            subset.remove(subset.size() - 1);
        }
    }

    // print directly
    public static void printSubsets(int k, int n) {
        List<Integer> subset = new ArrayList<>();
        print(subset, k, n, 1);
    }

    public static void print(List<Integer> subset, int k, int n, int num) {
        if (subset.size() == k) {
            count++;
            System.out.println(subset);
            return;
        }
        for (int i = num; i <= n; i++) {
            subset.add(i);
            print(subset, k, n, i + 1);
            subset.remove(subset.size() - 1);
        }
    }

    public static void main(String[] args) {
        Solution.printSubsets(2, 10);
        System.out.println("?" + Solution.count);
    }
}

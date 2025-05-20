// class Solution {
// public:
//     int fib(int n) {
//         int n1=0;
//         int n2=1;
//         int fn=1;
//         if (n==0){
//             return 0;
//         }
//         if (n==1){
//             return 1;
//         }
//         if (2<=n<=30){
//         for(int i=0;i<=n-2;i++){
//             fn=n1+n2;
//             n1=n2;
//             n2=fn;
//         }
//         }
//     return fn;
//     }
// };



//Recursive Approach
class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        return fib(n - 1) + fib(n - 2);
    }
};
 
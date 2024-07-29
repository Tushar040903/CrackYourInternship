bool isPossible(long long a[], long long b[], int n, long long k) {
        // Your code goes here
        sort(a,a+n);
        sort(b,b+n);
        reverse(b,b+n);
        
        for(int i=0;i<n;i++) {
            if(a[i]+b[i] < k) return false;
        }
        return true;
    }
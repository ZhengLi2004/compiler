void mergeSort(int l,int r){
    if(l==r)return;
    int mid=(l+r)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
}
    int arr[]={5,9,12,4,5,7,9,8,0,2,4,12,0,7};
    int t_element=sizeof(arr)/sizeof(arr[1]);
    //printf("%d",max(arr,t_element));
    printf("Arr is:");
    print(arr,t_element);
    radix_short(arr,t_element);
    printf("Short order:");
    print(arr,t_element);
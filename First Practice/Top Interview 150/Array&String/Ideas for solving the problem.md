# 88. Merge Sorted Array.c
從兩個陣列的尾部開始比較元素，從後往前填充 nums1，避免在合併時重複移動元素。
1. 開始：表示流程的開始。
2. 初始化指標：設置 i = m-1 和 j = n-1。
3. 檢查條件：是否 i >= 0 和 j >= 0？
4. 比較元素：如果 nums1[i] > nums2[j]，執行某操作；否則，執行另一操作。
5. 移動元素：將較大的元素放到 nums1[i+j+1]。
6. 更新指標：根據上一步比較的結果，更新 i 或 j。
7. 檢查是否還有未處理的 nums2 元素：是否 j >= 0？
8. 填充剩餘的 nums2 元素：將 nums2[j] 放到 nums1[i+j+1]，並更新 j。
9. 結束：所有元素處理完畢，流程結束。

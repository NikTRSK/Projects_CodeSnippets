// Returns the kth smallest value in  anArray[ﬁrst..last].
kSmall(k: integer, anArray: ArrayType,
        ﬁrst: integer, last: integer): ValueType 
Choose a pivot value p from anArray[ﬁrst..last]
Partition the values of anArray[ﬁrst..last] about p
if (k < pivotIndex - ﬁrst + 1) 
return kSmall(k, anArray, ﬁrst, pivotIndex - 1)
else if (k == pivotIndex - ﬁrst + 1) 
return p
else  
S
1
≤ p ≥ pp
return kSmall(k - (pivotIndex - ﬁrst + 1), anArray,
 pivotIndex + 1, last) 
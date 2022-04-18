# Add a 16-bit integer to an 8-bit summand


Description:

```cpp
                                   [mHigh mLow]    +
                                   [nHigh nLow]
                                   – – – – – – –
				   Low not overflow
                 [mHigh + nHigh] | [mLow + nLow]
		 		   else
	     [mHigh + nHigh + 1] | [mLow + nLow]
```

Code: 

```cpp

msbA = (numA & 0xFF00) >> 8;
lsbA = (numA & 0x00FF);

msbB = (numB & 0xFF00) >> 8;
lsbB = (numB & 0x00FF);

lResult = lsbA + lsbB;
  
if ((lsbA > 0) && (lsbB > 0) && (lsbA > (255 - lsbB)))
{
	mResult = msbA + msbB + 0x0001;
}
else
{
	mResult = msbA + msbB;
}

return  (mResult << 8) | (lResult & 0xFFFF);

```





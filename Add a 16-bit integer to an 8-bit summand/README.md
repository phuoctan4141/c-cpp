# Add a 16-bit integer to an 8-bit summand

<p align="center">[mHigh mLow]&nbsp&nbsp&nbsp+</p>
<p align="center">[nHigh nLow]&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp</p>
<p align="center">– – – – – – –&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp</p>
<p align="center"> not overflow &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp</p>
<p align="center">[mHigh + nHigh] | [mLow + nLow] &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp</p>
<p align="center"> else &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp</p>
<p align="center">[mHigh + nHigh + 1] | [mLow + nLow]&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp</p>





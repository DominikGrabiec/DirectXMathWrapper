XnaMathWrapper
==============

A simple C++ wrapper library for Microsoft's DirectXMath library (included in Windows SDK).

I have created this library as part of my current game and engine project (which I am doing just for fun and experimentation) to wrap the DirectXMath functions (and previously the D3D9X and XNAMath libraries math functions) in a more usable C++ form.

This library is not as efficient as using the DirectXMath functions directly, but it does add a nice level of expressiveness as I believe is shown in the intersection testing code (Intersect.cpp).

The code convention that I have used is pretty simple:
* 4 tab indentation, keeping the tabs.
* Use of C++11 code, including the STL where appropriate.
* UpperCamelCase for classes, and types.
* under_score for namespaces, functions, and public variables.
* UPPERCASE for constants.
* Anything goes for private members.

The code that I have written myself (i.e. not the STL or the DirectXMath library) I declare to be public domain, and hence it receives no warranty of any kind from me.
Please enjoy it, learn from it, and improve it if so desired.
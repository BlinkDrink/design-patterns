# Checksums
To setup this application you need to access both Projects' properties and do the following:
- In C/C++ -> General edit the `Additional Include Directories` to be that of ./openssl-1.1.0f-vs2017/include64 (there is provided source code for the openssl library in this repo)
- In Linker -> General edit the `Aditional Library Directories` to be that of ./openssl-1.1.0f-vs2017/lib64  
- In Linker -> Input edit the field so these values are present: 
	-ws2_32.lib
	-libsslMT.lib
	-Crypt32.lib
	-libcryptoMT.lib

This procedure should be done for both the Checksums project and it's TestingFramework project
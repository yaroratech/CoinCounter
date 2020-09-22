# CoinCounter

This project uses OpenCV image processing to classify the types of coins within an image (pennies, nickels, dimes, and quarters). It highlights each type of coin in a different color and prints out the total value of all the coins added together.

To compile the program, type: `g++ -o main main.cpp 'pkg-config opencv --cflags --libs'`

Here is an example: 
![image](https://user-images.githubusercontent.com/70921858/93930288-1ea70d80-fceb-11ea-8fc1-4c7407ee5fdb.png)

Given the above input image, the code produces this image:

![image](https://user-images.githubusercontent.com/70921858/93930392-4b5b2500-fceb-11ea-99b8-4b3b84b09cf1.png)

It also prints out the total value of the money like so: 
![image](https://user-images.githubusercontent.com/70921858/93931640-1354e180-fced-11ea-85f6-91255aab0d1f.png)

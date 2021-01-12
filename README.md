# IoT Smart Refrigerator

### Read our paper on [arXiv](https://arxiv.org/ftp/arxiv/papers/2012/2012.10422.pdf)


#### *Idea*
- Smart Refrigerator finds out the available stock of food items such as eggs , milk , jam, sauce etc present in it and sends a sms notification to the user’s designated mobile phone number via GSM module if any of these items are finished.
- It then waits for the user’s response (via text sms) on weather to place an order for that particular food item or not.
- If user replies ‘Yes’ then it places an order for that item to an designated grocery store again through a SMS along with required time of delivery.
- If the refrigerator does not gets an command from the user,scanning for that item is paused.
- It resumes scanning only after the item  is replenished back by the user. A threshold level can also be set for quantity of eggs, amount of milk and other items such that when the available stock goes below the threshold, similar action can be taken.


*Block Diagram of Proposed Model-*

![Block Diagram](https://github.com/Abhishek0697/IoT_Refrigerator/blob/master/docs/Block%20diagram.png)



### About GSM SIM 900A module

- SIM900A Modem is built with Dual Band GSM/GPRS based SIM900A modem from SIMCOM. It works on frequencies 900/ 1800 MHz. SIM900A can search these two bands automatically.The baud rate is configurable from 1200-115200 through AT command. This is a complete GSM/GPRS module in a SMT type and designed with a very powerful single-chip processor integrating AMR926EJ-S core, allowing you to benefit from small dimensions and cost-effective solutions.

*GSM SIM 900A -*

![GSM SIM 900A](https://github.com/Abhishek0697/IoT_Refrigerator/blob/master/docs/GSM%20SIM%20900A.PNG)


*Basic AT commands -*

![Basic AT commands](https://github.com/Abhishek0697/IoT_Refrigerator/blob/master/docs/Basic%20AT%20commands.PNG)




# Eggs Count and Ordering 
* In this model, an HC-04 Ultrasonic sensor is attached to the eggs tray. It continuously emits sound waves which reflect from the eggs placed in front of it and gives a particular distance. It has a maximum range of upto 400 cm. It can be programmed with the Arduino such that pre defining different ranges of distance we can calculate the presence of eggs as well as the quantity. Thus we raise an signal if the eggs are depleted or when a minimum threshold quantity is reached.The further operation is carried out  by the GSM module and the User.


*Principle of Ultrasonic Sensor -*

![Principle of Ultrasonic Sensor](https://github.com/Abhishek0697/IoT_Refrigerator/blob/master/docs/Principle%20of%20Ultrasonic%20Sensor.PNG)




# Milk Measurement and Ordering
* The IR unit is attached to the cap of the milk container facing inwards of the container such that it can measure the depth of the inside liquid.It has a range of 5cm to 30 cm. We define a level depending on the container size such that if the milk goes below that level i.e the reflected distance becomes large than the threshold set, an signal is raised and a similar operation of ordering is carried out. This application can be extended to other liquids and solid food items by defining different levels of threshold conditions as per requirement.


*Infrared Sensing Principle-*

![Infrared Sensing Principle](https://github.com/Abhishek0697/IoT_Refrigerator/blob/master/docs/Infrared%20Sensing%20Principle.PNG)




# Creation of  Interactive Interface 
- Using the GSM facility, an user can also send an inquiry request to the refrigerator about the present stock available in refrigerator. This feature can help in reducing over purchasing of some items while shopping and maintain household budget.
- Smart Refrigerator can also store information regarding nutritive values of vegetables,related Recipes etc. which the user can avail on demand by sending just an SMS to it. For instance it the user sends a text ‘Tomato’,then it get a SMS reply containing the nutrition content and google links to certain Recipes. For this we need to create a database in the Arduino for each of the items needed.




Notifications to User's Phone -

![Notification to User's Phone](https://github.com/Abhishek0697/IoT_Refrigerator/blob/master/docs/Notification%20to%20User's%20Phone.PNG)     
   
   
   
   
Message to Grocery Store -

![Message to Grocery Store](https://github.com/Abhishek0697/IoT_Refrigerator/blob/master/docs/Message%20to%20Grocery%20Store.PNG)

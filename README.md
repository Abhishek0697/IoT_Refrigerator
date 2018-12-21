# IoT_SmartRefrigerator

Idea:
Smart Refrigerator finds out the available stock of food items such as eggs , milk , jam, sauce etc present in it and sends a sms notification to the user’s designated mobile phone number via GSM module if any of these items are finished.
It then waits for the user’s response (via text sms) on weather to place an order for that particular food item or not.
If user replies ‘Yes’ then it places an order for that item to an designated grocery store again through a SMS along with required time of delivery.
If the refrigerator does not gets an command from the user,scanning for that item is paused.
It resumes scanning only after the item  is replenished back by the user.
A threshold level can also be set for quantity of eggs, amount of milk and other items such that when the available stock goes below the threshold, similar action can be taken.



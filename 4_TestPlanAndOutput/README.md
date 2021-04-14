# TEST PLAN:

## Table no: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01       |Checking all the options are executing properly |  By choosing 1 or 2 or 3 for the required operation| All the modes of operation are executed correctly|SUCCESS|Requirement based |
|  H_03       |Checking whether all the operations are performed according to the selection in each options| By choosing the number corresponding to the function  | All the functions are executed and obtained the correct results |SUCCESS|Scenario based    |
|  H_04       |Checking for other options other than specified in the program|  By choosing other values that are not mentioned| "Enter a valid option", is to be printed|SUCCESS|Boundary based    |

## Table no: Low level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       |Checking the login/signup part:<br/> 1.Whether the details are added to the database<br/> 2.Checking if the credentials are being compared with database| Choosing the login and signup part  | All details are added to the database(CSV file) and compared before creating the account |SUCCESS|Requirement based   |
|  L_02       |Checking the Food Delivery system  | By choosing different options | Coorect details according to the option |SUCCESS|Scenario based    |
|  L_03       |Checking other options other than specified |  By choosing other values that are not mentioned | "Enter a valid option" |SUCCESS|Boundary based |
|  L_04       |Checking Food menu | choosing the food, entering the quantity and clicking on cart | corresponding cost| The cost is displayed -SUCCESS |Scenario based |
|  L_05       |Checking Medicine menu | choosing the medicine, entering the quantity and clicking on cart | corresponding cost| The cost is displayed -SUCCESS |Scenario based |
|  L_06       |Checking the exit option | clicking the number corresponding to exit | confirmation for Exit and exit the program |Exited the program -SUCCESS |Boundary based    |
|  L_07       |Entering the cart and confirming the order | choosing cart and confirming the order | order confirmed and asking for location details |SUCCESS |Requirment based    |
|  L_08      |Checking the location function | getting location details | "location is received" | location is received - SUCCESS | Requirment based |
|  L_09      |Asking if the product is delivered or not | choosing the corresponding options | if product is delivered ask for OTP else exit with thankyou message | SUCCESS | Scenario based |
|  L_10      |Checking OTP authentication | entering the displayed OTP | OTP verification and delivering the product | OTP is verified and product is delivered - SUCCESS | Requirment based |

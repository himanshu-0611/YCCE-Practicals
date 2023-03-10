class Employee:
    company = "Google"
    def getSalary(self):
        print("Salary is 100k")

    @staticmethod    #self not needed
    def greet():
        print("Good morning sir")

harry = Employee()
harry.getSalary()    #This line is converted Employee.getSalary(harry) <- 1 argument given
harry.greet()
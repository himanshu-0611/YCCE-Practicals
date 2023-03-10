// System.Collections.Generic;
// using System.Linq;
// using System.Web;
// using System.Web.UI;
// using System.Web.UI.WebControls;
// namespace WebApplicationycce1 {
//     public partial class WebForm1 : System.Web.UI.Page {
//         protected void Page_Load(object sender, EventArgs e) {
//             if(RadioButtonList1.Text=="FAIL") { 
//                 Response.Write("You are Fail");
//             }
//         }
//         protected void Button1_Click(object sender, EventArgs e) { 
//             if(RadioButtonList1.Text=="PASS") {
//                 Response.Write("You are Pass");
//             } 
//         } 
//     } 
// }
<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebControls.aspx.cs"   
 Inherits="WebFormsControlls.WebControls" %>  
 <!DOCTYPE html>  
 <html xmlns="http://www.w3.org/1999/xhtml">  
 <head runat="server">  
     <title></title>  
 </head>  
 <body>  
     <form id="form1" runat="server">  
         <div>  
             <asp:RadioButton ID="RadioButton1" runat="server" Text="Male" GroupName="gender" />  
             <asp:RadioButton ID="RadioButton2" runat="server" Text="Female" GroupName="gender" />  
         </div>  
         <p>  
             <asp:Button ID="Button1" runat="server" Text="Submit" OnClick="Button1_Click" style="width: 61px" />  
         </p>  
     </form>  
     <asp:Label runat="server" id="genderId"></asp:Label>  
 </body>  
 </html>  
 
using System;  
using System.Collections.Generic;  
using System.Linq;  
using System.Web;  
using System.Web.UI;  
using System.Web.UI.WebControls;  
namespace WebFormsControlls  
{  
    public partial class WebControls : System.Web.UI.Page  
    {  
        protected void Button1_Click(object sender, EventArgs e)  
        {  
            genderId.Text = "";  
            if (RadioButton1.Checked)  
            {  
                genderId.Text = "Your gender is "+RadioButton1.Text;  
            }  
            else genderId.Text = "Your gender is "+RadioButton2.Text;  
  
        }  
    }  
}  
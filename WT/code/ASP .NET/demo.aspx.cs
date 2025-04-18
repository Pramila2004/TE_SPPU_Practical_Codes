using System;

namespace DemoApp
{
    public partial class Default : System.Web.UI.Page
    {
        protected void btnAsp_Click(object sender, EventArgs e)
        {
            lblMessage.Text = "ASP.NET Button Clicked! Server-side processing executed.";
        }
    }
}

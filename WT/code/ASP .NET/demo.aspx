<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="demo.aspx.cs" Inherits="DemoApp.Default" %>

<!DOCTYPE html>
<html>
<head>
    <title>Pramila Kolhe</title>
</head>
<body>
    <!-- HTML Button (Client-side only) -->

    <h3>HTML Control (No Server Interaction)</h3>
    <label for="">Enter your name : </label>
    <input type="text" id="txtHtml" value="HTML Control" />
    <button onclick="alert('HTML Button Clicked!')">Click Me</button>

    <!-- ASP.NET Button (Server-side interaction) -->

    <h3>ASP.NET Control (Server Interaction)</h3>
    <asp:Label ID="lblMessage" runat="server" ForeColor="Red"></asp:Label>
    <asp:TextBox ID="txtAsp" runat="server" Text="ASP.NET Control"></asp:TextBox>
    <asp:Button ID="btnAsp" runat="server" Text="Click Me" OnClick="btnAsp_Click" />
    

</body>
</html>

<%@ include file="base_datos.jsp" %>
<% 
base_datos bd= new base_datos("localhost","roni","12345678","mydb");
bd.conectar();
String dni = request.getParameter("dni");
String nom = request.getParameter("nombres");
String apelp = request.getParameter("apellidop");
String apelm = request.getParameter("apellidom");
String col = request.getParameter("color");
bd.insCliente(dni,nom,apelp,apelm,col);
ResultSet clientes = bd.getClientes();
while(clientes.next()){
 out.println("<tr>");
 out.println("<td>"+clientes.getString("dni")+"</td>");
 out.println("<td>"+clientes.getString("nombres")+"</td>");
 out.println("<td>"+clientes.getString("apellidop")+"</td>");
 out.println("<td>"+clientes.getString("apellidom")+"</td>");
 out.println("<td>"+clientes.getString("color")+"</td>");
 out.println("</tr>");
}
bd.cerrar();
%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include file="base_datos.jsp"%>

<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="UTF-8">
    <title>Formulario de Registro Clientes</title>
    <link rel="stylesheet" href="styles.css">
    <script src="formulario_clientes.js"></script>
  </head>
  <body>
    <div class="contenedor">
      <h2>Formulario de Registro</h2>
      <form>
        <div class="relleno">
          <div class="col_50">
            <input type="text" name="dni" id="dni" class="campos" placeholder="DNI...">
          </div>
          <div class="col_50">
            <input type="text" name="nombres" id="nombres" class="campos" placeholder="Nombres...">
          </div>
          <div class="col_50">
            <input type="text" name="apellidop" id="apellidop" class="campos" placeholder="Apellido Paterno...">
          </div>
          <div class="col_50">
            <input type="text" name="apellidom" id="apellidom" class="campos" placeholder="Apellido Materno...">
          </div>
          <div class="col_100">
            <fieldset>
              <legend class="color">Color Favorito:</legend>
              <input type="radio" name="color" value="Azul" id="azul">
              <label for="azul">Azul</label>
              <input type="radio" name="color" value="Verde" id="verde">
              <label for="verde">Verde</label>
              <input type="radio" name="color" value="Amarillo" id="amarillo">
              <label for="amarillo">Amarillo</label>
              <input type="radio" name="color" value="Celeste" id="celeste">
              <label for="celeste">Celeste</label>
              <input type="radio" name="color" value="Morado" id="morado">
              <label for="morado">Morado</label>
            </fieldset>
          </div>
          <button id="btnAgregar" class="btn" type="button">Agregar</button>
        </div>
      </form>
    </div>
    <h2>Clientes Registrados</h2>
    <table id="tablaUsuarios" class="tabla">
      <thead>
        <tr>
          <th>DNI</th>
          <th>Nombres</th>
          <th>Apellido Paterno</th>
          <th>Apellido Materno</th>
          <th>Color</th>
        </tr>
      </thead>
      <tbody id="contenido">
      <%
        base_datos bd= new base_datos("localhost","roni","12345678","mydb");
        bd.conectar();

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
      </tbody>
    </table>
  </body>
</html>

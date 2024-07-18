<?php include("base_datos.php");?>
<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="UTF-8">
    <title>Formulario Registro Clientes</title>
    <link rel="stylesheet" href="formulario.css">
    <script src="formulario_ajax.js"></script>
  </head>
  <body>
    <div class="contenedor">
      <h2>Formulario de Registro</h2>
      <form>
        <div class="relleno">
          <div class="col">
            <input class="campos" id="dni" type="text" placeholder="DNI...">
          </div>
          <div class="col">
            <input class="campos" id="nombre" type="text" placeholder="Nombre...">
          </div>
          <div class="col">
            <input class="campos" id="apellidop" type="text" placeholder="Apellido Paterno...">
          </div>
          <div class="col">
            <input class="campos" id="apellidom" type="text" placeholder="Apellido Materno...">
          </div>
          <div class="col" id="col_color">
            <input class="campos" id="color" type="text" placeholder="Color Favorito...">
          </div>
          <div class="col">
            <label for="desayuno">Desayuno</label>
            <input class="check" id="desayuno" type="checkbox">
          </div>
          <div class="col">
            <label for="auto">Auto</label>
            <input class="check" id="auto" type="checkbox">
          </div>
          <div class="col">
            <label for="limpieza">Limpieza Cuarto</label>
            <input class="check" id="limpieza" type="checkbox">
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
          <th>Desayuno</th>
          <th>Auto</th>
          <th>Limpieza</th>
        </tr>
      </thead>
      <tbody id="contenido">
        <?php
        $BaseDatos = new base_datos("localhost","roni","12345678","mydb");
        $BaseDatos->conectar();
        $clientes = $BaseDatos->getClientes();
        if(!is_null($clientes)){
          while($row = mysqli_fetch_assoc($clientes)){
            echo "<tr>";
            echo "<td>" . $row["dni"] . "</td>";
            echo "<td>" . $row["nombres"] . "</td>";
            echo "<td>" . $row["apellidop"] . "</td>";
            echo "<td>" . $row["apellidom"] . "</td>";
            echo "<td>" . $row["color"] . "</td>";
            echo "<td>" . boolTexto($row["desayuno"]) . "</td>";
            echo "<td>" . boolTexto($row["auto"]) . "</td>";
            echo "<td>" . boolTexto($row["limpieza"]) . "</td>";
            echo "</tr>";
          }
        }
        $BaseDatos->cerrar();
        ?>
      </tbody>
    </table>
  </body>
</html>

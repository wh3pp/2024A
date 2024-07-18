<?php
include("base_datos.php");
$BaseDatos = new base_datos("localhost","roni","12345678","mydb");
$BaseDatos->conectar();
$dni = $_POST["dni"];
$nom = $_POST["nombres"];
$apelp = $_POST["apellidop"];
$apelm = $_POST["apellidom"];
$color = $_POST["color"];
$desayuno = $_POST["desayuno"];
$auto = $_POST["auto"];
$limpieza = $_POST["limpieza"];
$BaseDatos->insCliente($dni,$nom,$apelp,$apelm,$color,$desayuno,$auto,$limpieza);
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

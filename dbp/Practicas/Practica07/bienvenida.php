<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <link rel="stylesheet" href="styles.css">
    <title>Bienvenida</title>
  </head>
  <body>
    <?php
    echo "<h2>Bienvenida</h2>";
    $nombre= $_POST["nombre"];
    $apellido= $_POST["apellido"];
    $animal= $_POST["animal"];
    $color= $_POST["color"];
    echo "Usted es ". $nombre . " " . $apellido . ". Su color favorito es " . $color . " y su animal favorito es " . $animal;
    ?>
  </body>
</html>

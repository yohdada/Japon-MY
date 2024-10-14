<!DOCTYPE html>
<html>
  <head>
    <title>Enregistrer des Lieux de Visite</title>
    <style>
      /* Style pour la carte et la liste des lieux */
      #map {
        height: 500px;
        width: 100%;
      }

      #form {
        margin-bottom: 20px;
      }

      .place-list {
        margin-top: 20px;
      }
    </style>
    <script
      src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDxTIm5Xpts7qb4byAd7qfBQOM0n8t2qok&libraries=places"
      defer
    ></script>
    <script>
      let map, marker;
      const places = {}; // Dictionnaire pour stocker les lieux par jour

      function initMap() {
        // Initialisation de la carte centrée sur Paris
        map = new google.maps.Map(document.getElementById("map"), {
          center: { lat: 48.8566, lng: 2.3522 },
          zoom: 12,
        });

        // Ajout d'un listener pour ajouter des lieux à la carte
        map.addListener("click", (event) => {
          addPlace(event.latLng);
        });
      }

      function addPlace(location) {
        if (marker) marker.setMap(null);

        marker = new google.maps.Marker({
          position: location,
          map: map,
        });

        const placeName = prompt("Entrez le nom du lieu:");
        const visitDay = prompt("Entrez le jour de visite (Ex: Jour 1):");

        if (placeName && visitDay) {
          if (!places[visitDay]) {
            places[visitDay] = [];
          }
          places[visitDay].push({ name: placeName, location: location });

          displayPlaces();
        }
      }

      function displayPlaces() {
        const placeList = document.getElementById("place-list");
        placeList.innerHTML = ""; // Réinitialiser la liste

        for (const day in places) {
          const dayHeader = document.createElement("h3");
          dayHeader.innerText = day;
          placeList.appendChild(dayHeader);

          const ul = document.createElement("ul");

          places[day].forEach((place) => {
            const li = document.createElement("li");
            li.innerText = place.name;
            ul.appendChild(li);
          });

          placeList.appendChild(ul);
        }
      }
    </script>
  </head>
  <body onload="initMap()">
    <h1>Enregistrer et Classer des Lieux de Visite</h1>
    <p>Cliquez sur la carte pour ajouter un lieu de visite. Vous pouvez le classer par jour de visite.</p>

    <div id="map"></div>

    <div class="place-list" id="place-list">
      <h2>Lieux classés par jour de visite</h2>
      <!-- Les lieux seront affichés ici -->
    </div>
  </body>
</html>
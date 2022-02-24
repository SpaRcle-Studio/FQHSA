/**
 * Author:    Andrea Casalino
 * Created:   03.12.2019
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include "DistanceMapper.h"
#include <omp.h>

namespace qh {

void DistanceMapper::updateAddedFacet(const hull::Facet *facet) {
  auto result = cloud.getFarthest(
      last_notification->context.vertices[facet->vertexA], facet->normal);
  if (nullptr != result) {
    facets_distances_map[facet] = result->distance;
    distances_facets_map.emplace(result->distance,
                                 FacetAndFarthestVertex{facet, result->vertex});
  }
}

void DistanceMapper::updateChangedFacet(const hull::Facet *facet) {
  auto result = cloud.getFarthest(
      last_notification->context.vertices[facet->vertexA], facet->normal);
  updateRemovedFacet(facet);
  if (nullptr != result) {
    facets_distances_map[facet] = result->distance;
    distances_facets_map.emplace(result->distance,
                                 FacetAndFarthestVertex{facet, result->vertex});
  }
}

void DistanceMapper::updateRemovedFacet(const hull::Facet *facet) {
  auto facets_distances_map_it = facets_distances_map.find(facet);
  auto range =
      distances_facets_map.equal_range(facets_distances_map_it->second);
  for (auto distances_facets_map_it = range.first;
       distances_facets_map_it != range.second; ++distances_facets_map_it) {
    if (distances_facets_map_it->second.facet == facet) {
      distances_facets_map.erase(distances_facets_map_it);
      break;
    }
  }
  facets_distances_map.erase(facets_distances_map_it);
}

void DistanceMapper::update() {
  // added facets
#pragma omp for
  for (const auto added : last_notification->added) {
    updateAddedFacet(added);
  }
// changed facets
#pragma omp for
  for (const auto changed : last_notification->added) {
    updateChangedFacet(changed);
  }
// removed facets
#pragma omp for
  for (const auto &removed : last_notification->removed) {
    updateRemovedFacet(removed.get());
  }
#pragma omp barrier
}
} // namespace qh

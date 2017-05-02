#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int
main (int argc, char** argv)
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

  if (pcl::io::loadPCDFile<pcl::PointXYZ> ("/home/ashvin/pointclouds/1459758038064520.pcd", *cloud) == -1) //* load the file
  {
    std::cout << "Failed to load\n";
    return (-1);
  }
  std::cout << "Loaded "
            << cloud->width * cloud->height
            << " data points from test_pcd.pcd with the following fields: "
            << std::endl;
  for (size_t i = 0; i < cloud->points.size (); ++i)
    std::cout << "RGB    " << cloud->points[i].r
              << " "    << cloud->points[i].g
              << " "    << cloud->points[i].b << std::endl;

  return (0);
}
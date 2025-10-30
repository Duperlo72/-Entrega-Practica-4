#include <iostream>
#include <vector>
using namespace std;


class Producto {
    private:
        string nombre;
        int precio;
        int stock;
    
    public:
        Producto(string n, int p, int s)
            : nombre(n), precio(p), stock(s) {}
    
        string getNombre() const { return nombre; }
        int getPrecio() const { return precio; }
        int getStock() const { return stock; }
    
        void mostrarProducto() const {
            cout << "Producto: " << nombre
                 << " | Precio: $" << precio
                 << " | Stock: " << stock << endl;
        }
    };
    

    class ItemCarrito {
    private:
        Producto producto;
        int cantidad;
    
    public:
        ItemCarrito(const Producto& prod, int c)
            : producto(prod), cantidad(c) {}
    
        int getCantidad() const { return cantidad; }
        Producto getProducto() const { return producto; }
    
        void mostrarItem() const {
            cout << producto.getNombre()
                 << " x" << cantidad
                 << " = $" << producto.getPrecio() * cantidad << endl;
        }
    };
    

    class Carrito {
        private:
            vector<ItemCarrito> items;
        
        public:
            void agregarItem(const ItemCarrito& item) {
                items.push_back(item);
            }
        
            void mostrarCarrito() const {
                cout << "\nCarrito de compras:" << endl;
                for (const auto& item : items) {
                    item.mostrarItem();
                }
            }
        
            int totalCarrito() const {
                int total = 0;
                for (const auto& item : items) {
                    total += item.getProducto().getPrecio() * item.getCantidad();
                }
                return total;
            }
        };
        
    

    class Usuario {
    private:
        string nombreUsuario;
        string contrasena;
        Carrito carrito;
    
    public:
        Usuario(string nu, string co)
            : nombreUsuario(nu), contrasena(co) {}
    
        string getNombreUsuario() const { return nombreUsuario; }
    
        void agregarAlCarrito(const ItemCarrito& item) {
            carrito.agregarItem(item);
        }
    
        void mostrarUsuario() const {
            cout << "\n Usuario: " << nombreUsuario << endl;
            carrito.mostrarCarrito();
            cout << "Total a pagar: $" << carrito.totalCarrito() << endl;
        }
    };
    
    int main() {
        // Productos disponibles
        Producto p1("Manzana", 1000, 50);
        Producto p2("Pan", 1500, 30);
        Producto p3("Leche", 2500, 20);
    
        // Usuario
        Usuario u1("Faro", "1234");
    
        // Agrega productos al carrito
        u1.agregarAlCarrito(ItemCarrito(p1, 3));
        u1.agregarAlCarrito(ItemCarrito(p2, 2));
        u1.agregarAlCarrito(ItemCarrito(p3, 1));
    
        // Muestra el carrito del usuario
        u1.mostrarUsuario();
    
        return 0;
    }
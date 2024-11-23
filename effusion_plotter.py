#/* --------------------------------------------------------------------------------
#   Egorov Group
#   University of Virginia
#   Mohan Shankar
#
#   2d_slit.py
#   "This file calculates eigenfunctions of particle in a box in the presence of a slit"
#-------------------------------------------------------------------------------- */
# DEPENDENCIES
import numpy as np
import matplotlib.pyplot as plt
import time
#-------------------------------------------------------------------------------- */
start_time = time.time()


# INPUTS
me = 5.485799e-4 # Electron mass in daltons
m_au = 1.0 / me

lx = 1.0 # Angstroms
ly = 8.0 # Angstroms

a0 = 0.529177258 # Bohr radius

lx_au = lx/a0
ly_au = ly/a0 

nnx = 60 # number of points in x; set low for debugging
nny = 60 # number of points in y; set low for debugging

xmin = 0
xmax = lx_au

ymin = 0
ymax = ly_au

dx = (xmax-xmin)/(nnx+1)
dy = (ymax-ymin)/(nny+1)

pi = np.pi

nd = 2 # length of stencil 
wall_thickness = 2
cd = np.zeros(nd) 
nn = 10 # number of points on dividing surface?
gap_size = 10.0
#-------------------------------------------------------------------------------- */
# FUNCTION DEFINITIONS

def kron_sum(A1, A2):
    '''
    Assumes A1, A2 are nxn, mxm matrices where n can be equal to m
    '''
    i1 = np.identity(len(A1[0]))
    i2 = np.identity(len(A2[0]))
    return np.kron(A1,i2) + np.kron(i1, A2)


def PIB_one(points, lmax, lmin, mass, hbar=1):  
    '''
    function to return eigenvalues and eigenvectors of a Hamiltonian matrix 
    eigvals returned in array where eigvals[0] gives a float corresponding to n = 1; units of Joules since I defined my analytic formula with SI units
    eigvecs returned in array of arrays where eigvecs[:, i] (column vectors) gives an array corresponding to n = i at each point in the box defined by grid spacing dx
    '''
    dn = (lmax-lmin)/(points+1)
    dn2 = dn**2  # second derivative
    H = np.zeros((points, points)) # initialize 
    z = -pi**2/3.0  # weight for diagonal
    for i in range(points):
        for j in range(points):
            if i == j:
                H[i][j] = z # weight for diagonals of matrix
            else:
                H[i][j] = (2/(i-j)**2)*((-1)**(i-j+1))  # weights for non-diagonals
    H *= (-1/(2*mass*dn2)) # hbar = 1 hence 1/(2 * mass * dn2)
    return H
#-------------------------------------------------------------------------------- */
# CREATE MATRICES 
h1_x = PIB_one(nnx, xmax, xmin, m_au) # 1-D Hamiltonian from x points
h1_y = PIB_one(nny, ymax, ymin, m_au) # 1-D Hamiltonian from y points

H = kron_sum(h1_x, h1_y) # 2-D Hamiltonian
# STENCIL FOR FLUX ALONG DIVIDING SURFACE
for k in range(nd):
    zz = 1.0
    for j in range(nd):
        if j != k:
            zz *= ((j+1)**2) / ((j+1)**2 - (k+1)**2)
        else:
            continue
    cd[k] = zz/(2*(k+1))

print("Matrices created!")
#-------------------------------------------------------------------------------- */
# MAKE EFFUSION SLIT BY ZEROING OUT HAMILTONIAN
i = -1

for k in range(nnx):
    for j in range(nny):
        i = i+1
        x = dx * k + xmin
        y = dy * j + ymin
        if (1.0 / a0) < y < (1.0 / a0 + wall_thickness * dy):
            if x <(0.5 * xmax - (gap_size/2) * dx) or x >(0.5 * xmax + (gap_size/2) * dx):
                H[i] = np.zeros(nnx * nny)
                H[:, i] = np.zeros(nnx * nny)
                H[i, i] = -1
print("Slit created!")
#-------------------------------------------------------------------------------- */
# CALCULATE EIGENVECTORS AND VALUES
eigvals, eigvecs = np.linalg.eigh(H) # find eigenvalues and eigenvectors
print("Eigs found!")
#-------------------------------------------------------------------------------- */
# CLEANUP OF DATA
psi = np.transpose(eigvecs) # vectors returned in column form so take transpose for easier indexing

psi = psi[np.argsort(eigvals)]
energies = eigvals[np.argsort(eigvals).real]

cut = np.where(energies > 0)
print(cut)
energies = energies[cut]
psi = psi[cut]

for i in range(len(psi)):
    normalization = np.sqrt(np.sum(psi[i]**2 * dy * dx))
    psi[i] = psi[i]/normalization

print("Eigs done!")
#-------------------------------------------------------------------------------- */
# PLOTTING
a = 4 # excited state value

psi_plot = psi[a].reshape(nnx, nny)
psi_2 = psi[a]**2

x1, y2 = np.linspace(0, xmax, nnx), np.linspace(0, ymax, nny) 
x, y = np.meshgrid(y2, x1)

# # print("x shape", x.shape)
# # print("y shape", y.shape)

# plt.subplots(figsize=(15, 5))

# PLOT ONE, PSI
# plt.subplot(1, 2, 1)

# num_plot = plt.contourf(x, y, psi_plot.reshape(nnx, nny))
# num_cb = plt.colorbar(num_plot, orientation = 'horizontal')
# num_cb.set_label(r"$\Psi $, Energy State: "+str(a))

# # PLOT TWO, PSI^2
# plt.subplot(1, 2, 2)
# num_plot = plt.contourf(x, y, psi_2.reshape(nnx, nny))
# num_cb = plt.colorbar(num_plot, orientation = 'horizontal')
# num_cb.set_label(r"$| \Psi |^2$, Energy State: "+str(a))

# SHOW PLOT
# plt.savefig("/Users/mohan/Desktop/plz.png", dpi = 500)
# plt.show()

## THESE ONES LOOK BETTER

num_plot = plt.imshow(psi_plot.reshape(nnx, nny))
num_cb = plt.colorbar(num_plot, orientation = 'horizontal')
num_cb.set_label(r"$\Psi $, Energy State: "+str(a))
# plt.savefig("/Users/mohan/Desktop/2pt_wall-10pt_gap-"+str(a)+"excited.png", dpi = 600)

plt.show()

# plt.subplots(figsize=(15, 5))

# PLOT ONE, PSI
# plt.subplot(1, 2, 1)

# num_plot = plt.imshow(psi_plot.reshape(nnx, nny))
# num_cb = plt.colorbar(num_plot, orientation = 'horizontal')
# num_cb.set_label(r"$\Psi $, Energy State: "+str(a))

# PLOT TWO, PSI^2
# plt.subplot(1, 2, 2)
# num_plot2 = plt.imshow(psi_2.reshape(nnx, nny))
# num_cb2 = plt.colorbar(num_plot2, orientation = 'horizontal')
# num_cb2.set_label(r"$ |\Psi|^2 $, Energy State: "+str(a))
# plt.savefig("/Users/mohan/Desktop/psi"+str(a)+".png", dpi = 500)
# plt.show()
#-------------------------------------------------------------------------------- */

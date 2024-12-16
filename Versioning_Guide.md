# Versioning Guide
<sup>Ganti ke Bahasa Indonesia? [Klik disini!](Panduan_Pengelolaan_Versi.md)</sup>

All notable changes to this project will adhere this versioning system. For detailed information, check [semantic versioning](https://semver.org/spec/v2.0.0.html).

Semantic versioning in this project uses this format:
```bash
X.Y.Z
```
that corresponds to
```bash
MAJOR.MINOR.PATCH
```
Details:
1. **MAJOR** indicates major changes that are incompatible with previous versions.
	- Example: Redesigning new architecture and changing the core functionality
	- Increment: `1.0.0` &rarr; `2.0.0`

2. **MINOR** indicates changes that are backward-compatible with the addition of new features
	- Example: Adding new sensor
	- Increment: `1.1.0` &rarr; `1.2.0`

3. **PATCH** indicates minor changes that do not add new features but solve issues or optimize existing functionalities
	- Example: Bug fixing, replacing faulty component
	- Increment: `1.1.1` &rarr; `1.1.2`
